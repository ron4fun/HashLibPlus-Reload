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

#include "IHash.h"
#include "IKDF.h"
#include "IBlake2BConfigurations/IBlake2BConfig.h"
#include "IBlake2BConfigurations/IBlake2BTreeConfig.h"
#include "IBlake2SConfigurations/IBlake2SConfig.h"
#include "IBlake2SConfigurations/IBlake2STreeConfig.h"
#include "../Enum/Argon2Type.h"
#include "../Enum/Argon2Version.h"
#include "../Nullable/Nullable.h"

class ITransformBlock
{}; // end class ITransformBlock


class IBlockHash : public virtual IHash
{ }; // end IBlockHash


class INonBlockHash
{ }; // end INonBlockHash


class IChecksum
{ }; // end IChecksum


class ICrypto : public virtual IBlockHash
{ }; // end ICrypto


class ICryptoNotBuildIn : public virtual ICrypto
{ }; // end ICryptoNotBuildIn


class IWithKey : public virtual IHash
{
public:
	virtual HashLibByteArray GetKey() const = 0;
	virtual void SetKey(const HashLibByteArray& value) = 0;
	virtual NullableInteger GetKeyLength() const = 0;
}; // end IWithKey


class IMAC : public virtual IHash
{
public:
	virtual void Clear() = 0;

	virtual HashLibByteArray GetKey() const = 0;
	virtual void SetKey(const HashLibByteArray& value) = 0;
}; // end IMAC


class IMACNotBuildIn : public virtual IMAC
{};


class IHMAC : public virtual IMACNotBuildIn
{}; // end IHMAC


class IHMACNotBuildIn : public virtual IHMAC
{
public:
	virtual HashLibByteArray GetWorkingKey() const = 0;
}; // end IHMACNotBuildIn


class IKMAC : public virtual IMACNotBuildIn
{ }; // end IKMAC


class IKMACNotBuildIn : public virtual IKMAC
{ }; // end IKMACNotBuildIn


#pragma region Blake2 Interfaces

class IBlake2BMAC : public virtual IMACNotBuildIn
{}; // end IBlake2BMAC


class IBlake2BMACNotBuildIn : public virtual IBlake2BMAC
{}; // end IBlake2BMACNotBuildIn


class IBlake2SMAC : public virtual IMACNotBuildIn
{}; // end IBlake2SMAC


class IBlake2SMACNotBuildIn : public virtual IBlake2SMAC
{}; // end IBlake2SMACNotBuildIn


#pragma endregion


#pragma region Blake2X _config Interfaces


class IBlake2XBConfig
{
public:
	virtual ~IBlake2XBConfig() {}

	virtual IBlake2BConfig& GetConfig() const = 0;
	virtual IBlake2BTreeConfig& GetTreeConfig() const = 0;

	virtual IBlake2BConfig& GetConfig() = 0;
	virtual IBlake2BTreeConfig& GetTreeConfig() = 0;

	virtual void SetConfig(const IBlake2BConfig& value) = 0;
	virtual void SetTreeConfig(const IBlake2BTreeConfig& value) = 0;

	virtual IBlake2XBConfig& Clone() const = 0;

}; // end class IBlake2XBConfig


class IBlake2XSConfig
{
public:
	virtual ~IBlake2XSConfig() {}

	virtual IBlake2SConfig& GetConfig() const = 0;
	virtual IBlake2STreeConfig& GetTreeConfig() const = 0;

	virtual IBlake2SConfig& GetConfig() = 0;
	virtual IBlake2STreeConfig& GetTreeConfig() = 0;

	virtual void SetConfig(const IBlake2SConfig& value) = 0;
	virtual void SetTreeConfig(const IBlake2STreeConfig& value) = 0;

	virtual IBlake2XSConfig& Clone() const = 0;
};

#pragma endregion


class IHash16 : public virtual IHash
{ }; // end IHash16


class IHash32 : public virtual IHash
{ }; // end IHash32


class IHash64 : public virtual IHash
{ }; // end IHash64


class IHash128 : public virtual IHash
{ }; // end IHash128


class IHashWithKey : public virtual IWithKey
{}; // end IHashWithKey


#pragma region KDF Interfaces


class IKDFNotBuildIn : public virtual IKDF
{
public:
	virtual IKDFNotBuildIn& Clone() const = 0;
}; // end IKDFNotBuildIn


class IPBKDF2_HMAC : public virtual IKDFNotBuildIn
{}; // end IPBKDF2_HMAC


class IPBKDF2_HMACNotBuildIn : public virtual IPBKDF2_HMAC
{}; // end IPBKDF2_HMACNotBuildIn


class IPBKDF_Argon2 : public virtual IKDFNotBuildIn
{}; // end IPBKDF_Argon2


class IPBKDF_Argon2NotBuildIn : public virtual IPBKDF_Argon2
{ }; // end IPBKDF_Argon2NotBuildIn


class IPBKDF_Scrypt : public virtual IKDFNotBuildIn
{ }; // end IPBKDF_Scrypt


class IPBKDF_ScryptNotBuildIn : public virtual IPBKDF_Scrypt
{ }; // end IPBKDF_ScryptNotBuildIn


class IPBKDF_Blake3 : public virtual IKDFNotBuildIn
{ }; // end IPBKDF_Blake3


class IPBKDF_Blake3NotBuildIn : public virtual IPBKDF_Blake3
{ }; // end IPBKDF_Blake3NotBuildIn


class IXOF : public virtual IHash
{
public:
	virtual UInt64 GetXOFSizeInBits() const = 0;
	virtual void SetXOFSizeInBits(const UInt64 value) = 0;

	virtual void DoOutput(HashLibByteArray& destination, const UInt64 destinationOffset, const UInt64 outputLength) = 0;
}; // end IXOF


#pragma endregion



#pragma region Argon2 Parameter Interfaces


class IArgon2Parameters
{
public:
	virtual void Clear() = 0;

	virtual HashLibByteArray GetSalt() const = 0;
	virtual HashLibByteArray GetSecret() const = 0;
	virtual HashLibByteArray GetAdditional() const = 0;
	virtual Int32 GetIterations() const = 0;
	virtual Int32 GetMemory() const = 0;
	virtual Int32 GetLanes() const = 0;
	virtual Argon2Type GetType() const = 0;
	virtual Argon2Version GetVersion() const = 0;

	virtual IArgon2Parameters& Clone() const = 0;
};  // end IArgon2Parameters


class IArgon2ParametersBuilder
{
public:
	virtual IArgon2ParametersBuilder& WithParallelism(const Int32 a_parallelism) = 0;

	virtual IArgon2ParametersBuilder& WithSalt(const HashLibByteArray& a_salt) = 0;

	virtual IArgon2ParametersBuilder& WithSecret(const HashLibByteArray& a_secret) = 0;

	virtual IArgon2ParametersBuilder& WithAdditional(const HashLibByteArray& a_additional) = 0;

	virtual IArgon2ParametersBuilder& WithIterations(const Int32 a_iterations) = 0;

	virtual IArgon2ParametersBuilder& WithMemoryAsKiB(const Int32 a_memory) = 0;

	virtual IArgon2ParametersBuilder& WithMemoryPowOfTwo(const Int32 a_memory) = 0;

	virtual IArgon2ParametersBuilder& WithType(const Argon2Type& a_type) = 0;

	virtual IArgon2ParametersBuilder& WithVersion(const Argon2Version& a_version) = 0;

	virtual void Clear() = 0;

	virtual IArgon2ParametersBuilder& Build() const = 0;

}; // end IArgon2ParametersBuilder


#pragma endregion
