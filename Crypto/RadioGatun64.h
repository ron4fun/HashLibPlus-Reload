///////////////////////////////////////////////////////////////////////
/// SharpHash Library
/// Copyright(c) 2021 Mbadiwe Nnaemeka Ronald
/// Github Repository <https://github.com/ron4fun/HashLibPlus>
///
/// The contents of this file are subject to the
/// Mozilla Public License Version 2.0 (the "License");
/// you may not use this file except in
/// compliance with the License. You may obtain a copy of the License
/// at https://www.mozilla.org/en-US/MPL/2.0/
///
/// Software distributed under the License is distributed on an "AS IS"
/// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
/// the License for the specific language governing rights and
/// limitations under the License.
///
/// Acknowledgements:
///
/// Thanks to Ugochukwu Mmaduekwe (https://github.com/Xor-el) for his creative
/// development of this library in Pascal/Delphi (https://github.com/Xor-el/HashLib4Pascal).
///
////////////////////////////////////////////////////////////////////////

#pragma once

#include "../Base/HashCryptoNotBuildIn.h"

class RadioGatun64 final : public BlockHash, public ICryptoNotBuildIn, public ITransformBlock
{
public:
	RadioGatun64()
		: BlockHash(32, 24)
	{
		_name = __func__;

		_mill.resize(19);
		
		_belt.resize(13);
		for (UInt32 i = 0; i < 13; i++)
			_belt[i] = HashLibUInt64Array(3);

	} // end constructor

	IHash& Clone() const override
	{
		RadioGatun64* HashInstance = new RadioGatun64();
		HashInstance->_mill = _mill;
		HashInstance->_belt = _belt;
		HashInstance->_buffer = _buffer.Clone();
		HashInstance->_processed_bytes = _processed_bytes;

		HashInstance->SetBufferSize(GetBufferSize());

		return *HashInstance;
	}

	void Initialize() override
	{
		ArrayUtils::zeroFill(_mill);

		for (UInt32 i = 0; i < 13; i++)
			ArrayUtils::zeroFill(_belt[i]);

		BlockHash::Initialize();
	} // end function Initialize

protected:
	void Finish() override
	{
		Int32 padding_size = 24 - (_processed_bytes % 24);

		HashLibByteArray pad = HashLibByteArray(padding_size);

		pad[0] = 0x01;

		TransformBytes(pad, 0, padding_size);

		for (UInt32 i = 0; i < 16; i++)
			RoundFunction();

	} // end function Finish

	HashLibByteArray GetResult() override
	{
		HashLibUInt64Array tempRes = HashLibUInt64Array(4);

		HashLibByteArray result = HashLibByteArray(4 * sizeof(UInt64));

		for (UInt32 i = 0; i < 2; i++)
		{
			RoundFunction();
			memmove(&tempRes[(size_t)i * 2], &_mill[1], 2 * sizeof(UInt64));
		} // end for

		Converters::le64_copy(&tempRes[0], 0, &result[0], 0, (Int32)result.size());

		return result;
	} // end function GetResult

	void TransformBlock(const uint8_t* a_data,
		const Int32 a_data_length, const Int32 a_index) override
	{
		HashLibUInt64Array data = HashLibUInt64Array(3);

		Converters::le64_copy(a_data, a_index, &data[0], 0, 24);

		UInt32 i = 0;
		while (i < 3)
		{
			_mill[(size_t)i + 16] = _mill[(size_t)i + 16] ^ data[i];
			_belt[0][i] = _belt[0][i] ^ data[i];
			i++;
		} // end while

		RoundFunction();

		ArrayUtils::zeroFill(data);
	} // end function TransformBlock

private:
	inline void RoundFunction()
	{
		HashLibUInt64Array q = _belt[12];
		HashLibUInt64Array a = HashLibUInt64Array(19);

		UInt32 i = 12;
		while (i > 0)
		{
			_belt[i] = _belt[i - 1];
			i--;
		} // end while

		_belt[0] = q;

		i = 0;
		while (i < 12)
		{
			_belt[(size_t)i + 1][i % 3] = _belt[(size_t)i + 1][i % 3] ^ _mill[(size_t)i + 1];
			i++;
		} // end while

		i = 0;
		while (i < 19)
		{
			a[i] = _mill[i] ^ (_mill[(i + 1) % 19] | ~_mill[(i + 2) % 19]);
			i++;
		} // end while

		i = 0;
		while (i < 19)
		{
			_mill[i] = Bits::RotateRight64(a[(7 * i) % 19], (i * (i + 1)) >> 1);
			i++;
		} // end while

		i = 0;
		while (i < 19)
		{
			a[i] = _mill[i] ^ _mill[(i + 1) % 19] ^ _mill[(i + 4) % 19];
			i++;
		} // end while

		a[0] = a[0] ^ 1;

		i = 0;
		while (i < 19)
		{
			_mill[i] = a[i];
			i++;
		} // end while

		i = 0;
		while (i < 3)
		{
			_mill[(size_t)i + 13] = _mill[(size_t)i + 13] ^ q[i];
			i++;
		} // end while
	} // end function RoundFunction

private:
	HashLibUInt64Array _mill;

	HashLibMatrixUInt64Array _belt;

}; // end class RadioGatun64
