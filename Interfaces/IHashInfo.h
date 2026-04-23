///////////////////////////////////////////////////////////////////////
/// SharpHash Library
/// Copyright(c) 2021 - 2026 Mbadiwe Nnaemeka Ronald
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

#include "IHash.h"
#include "IKDF.h"
#include "../Enum/Argon2Type.h"
#include "../Enum/Argon2Version.h"
#include "../Nullable/Nullable.h"

class IIHashWithKey;
class IIPBKDF2_HMACNotBuildIn;
class IIPBKDF_ScryptNotBuildIn;
class IIPBKDF_Blake3NotBuildIn;
class IIPBKDF_Argon2NotBuildIn;
class IIMACNotBuildIn;
class IIHMACNotBuildIn;
class IIKMACNotBuildIn;
class IIKDFNotBuildIn;
class IIBlake2BMACNotBuildIn;
class IIBlake2SMACNotBuildIn;
class IIXOF;

// wrap hash to support reference 
// counting and auto freeing of memory.
typedef shared_ptr<IIHashWithKey> IHashWithKey;
typedef shared_ptr<IIPBKDF2_HMACNotBuildIn> IPBKDF2_HMACNotBuildIn;
typedef shared_ptr<IIPBKDF_ScryptNotBuildIn> IPBKDF_ScryptNotBuildIn;
typedef shared_ptr<IIPBKDF_Blake3NotBuildIn> IPBKDF_Blake3NotBuildIn;
typedef shared_ptr<IIPBKDF_Argon2NotBuildIn> IPBKDF_Argon2NotBuildIn;
typedef shared_ptr<IIMACNotBuildIn> IMACNotBuildIn;
typedef shared_ptr<IIHMACNotBuildIn> IHMACNotBuildIn;
typedef shared_ptr<IIKMACNotBuildIn> IKMACNotBuildIn;
typedef shared_ptr<IIKDFNotBuildIn> IKDFNotBuildIn;
typedef shared_ptr<IIBlake2BMACNotBuildIn> IBlake2BMACNotBuildIn;
typedef shared_ptr<IIBlake2SMACNotBuildIn> IBlake2SMACNotBuildIn;
typedef shared_ptr<IIXOF> IXOF;


class IITransformBlock
{}; // end class IITransformBlock


class IIBlockHash : public virtual IIHash
{ }; // end IIBlockHash


class IINonBlockHash
{ }; // end IINonBlockHash


class IIChecksum
{ }; // end IIChecksum


class IICrypto : public virtual IIBlockHash
{ }; // end IICrypto


class IICryptoNotBuildIn : public virtual IICrypto
{ }; // end IICryptoNotBuildIn


class IIWithKey : public virtual IIHash
{
public:
	virtual HashLibByteArray GetKey() const = 0;
	virtual void SetKey(const HashLibByteArray& value) = 0;
	virtual NullableInteger GetKeyLength() const = 0;
}; // end IIWithKey


class IIMAC : public virtual IIHash
{
public:
	virtual void Clear() = 0;

	virtual HashLibByteArray GetKey() const = 0;
	virtual void SetKey(const HashLibByteArray& value) = 0;
}; // end IMAC


class IIMACNotBuildIn : public virtual IIMAC
{
public:
	virtual IMACNotBuildIn CloneMAC() const = 0;
};


class IIHMAC : public virtual IIMACNotBuildIn
{}; // end IIHMAC


class IIHMACNotBuildIn : public virtual IIHMAC
{
public:
	virtual IHMACNotBuildIn CloneHMAC() const = 0;
	virtual HashLibByteArray GetWorkingKey() const = 0;
}; // end IIHMACNotBuildIn


class IIKMAC : public virtual IIMACNotBuildIn
{ }; // end IIKMAC


class IIKMACNotBuildIn : public virtual IIKMAC
{ }; // end IIKMACNotBuildIn


#pragma region Blake2 Interfaces

class IIBlake2BMAC : public virtual IIMACNotBuildIn
{}; // end IIBlake2BMAC


class IIBlake2BMACNotBuildIn : public virtual IIBlake2BMAC
{}; // end IIBlake2BMACNotBuildIn


class IIBlake2SMAC : public virtual IIMACNotBuildIn
{}; // end IIBlake2SMAC


class IIBlake2SMACNotBuildIn : public virtual IIBlake2SMAC
{}; // end IIBlake2SMACNotBuildIn


#pragma endregion


class IIHash16 : public virtual IIHash
{ }; // end IIHash16


class IIHash32 : public virtual IIHash
{ }; // end IIHash32


class IIHash64 : public virtual IIHash
{ }; // end IIHash64


class IIHash128 : public virtual IIHash
{ }; // end IIHash128


class IIHashWithKey : public virtual IIWithKey
{
public:
	virtual IHashWithKey CloneHashWithKey() const = 0;
}; // end IIHashWithKey


#pragma region KDF Interfaces


class IIKDFNotBuildIn : public virtual IIKDF
{
public:
	virtual IKDFNotBuildIn Clone() const = 0;
}; // end IIKDFNotBuildIn


class IIPBKDF2_HMAC : public virtual IIKDFNotBuildIn
{}; // end IIPBKDF2_HMAC


class IIPBKDF2_HMACNotBuildIn : public virtual IIPBKDF2_HMAC
{}; // end IIPBKDF2_HMACNotBuildIn


class IIPBKDF_Argon2 : public virtual IIKDFNotBuildIn
{}; // end IIPBKDF_Argon2


class IIPBKDF_Argon2NotBuildIn : public virtual IIPBKDF_Argon2
{ }; // end IIPBKDF_Argon2NotBuildIn


class IIPBKDF_Scrypt : public virtual IIKDFNotBuildIn
{ }; // end IIPBKDF_Scrypt


class IIPBKDF_ScryptNotBuildIn : public virtual IIPBKDF_Scrypt
{ }; // end IIPBKDF_ScryptNotBuildIn


class IIPBKDF_Blake3 : public virtual IIKDFNotBuildIn
{ }; // end IIPBKDF_Blake3


class IIPBKDF_Blake3NotBuildIn : public virtual IIPBKDF_Blake3
{ }; // end IIPBKDF_Blake3NotBuildIn


class IIXOF : public virtual IIHash
{
public:
	virtual IXOF CloneXOF() const = 0;
	virtual UInt64 GetXOFSizeInBits() const = 0;
	virtual void SetXOFSizeInBits(const UInt64 value) = 0;

	virtual void DoOutput(HashLibByteArray& destination, const UInt64 destinationOffset, const UInt64 outputLength) = 0;
}; // end IIXOF


#pragma endregion
