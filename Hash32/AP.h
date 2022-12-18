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

#include "../Base/Hash.h"
#include "../Interfaces/IHashInfo.h"


class AP : public Hash, public virtual IIHash32, public virtual IITransformBlock
{
public:
	AP()
		: Hash(4, 1)
	{
		_name = __func__;
	} // end constructor

	virtual IHash Clone() const
	{
		AP HashInstance = AP();
		HashInstance._hash = _hash;
		HashInstance._index = _index;

		HashInstance.SetBufferSize(GetBufferSize());

		return make_shared<AP>(HashInstance);
	}

	virtual void Initialize()
	{
		_hash = 0xAAAAAAAA;
		_index = 0;
	} // end function Initialize

	virtual IHashResult TransformFinal()
	{
		IHashResult result = make_shared<HashResult>(_hash);

		Initialize();

		return result;
	} // end function TransformFinal

	virtual void TransformBytes(const HashLibByteArray& a_data, const Int32 a_index, const Int32 a_length)
	{
		UInt32 i = a_index, length = a_length;

		while (length > 0)
		{
			if ((_index & 1) == 0)
				_hash = _hash ^ ((_hash << 7) ^ a_data[i] * (_hash >> 3));
			else
				_hash = _hash ^ (~((_hash << 11) ^ a_data[i] ^ (_hash >> 5)));

			_index++;
			i++;
			length--;
		} // end while
	} // end function TransformBytes

private:
	UInt32 _hash;
	Int32 _index;

}; // end class AP
