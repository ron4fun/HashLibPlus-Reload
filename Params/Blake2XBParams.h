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

#include "Blake2BParams.h"
#include "../Interfaces/IHashInfo.h"

/// <summary>
/// <b>Blake2XBConfig</b> is used to configure _hash function parameters and
/// keying.
/// </summary>
class Blake2XBConfig final
{
private:
	Blake2BConfig _config;
	Blake2BTreeConfig _treeConfig;

public:
	Blake2XBConfig() 
		: _treeConfig(Blake2BTreeConfig(true)) 
	{}

	Blake2XBConfig(const Blake2BConfig& config, const Blake2BTreeConfig& treeConfig)
	{
		_config = config;
		_treeConfig = treeConfig;
	}

	~Blake2XBConfig()
	{}

	Blake2BConfig GetConfig() const
	{
		return _config;
	}

	Blake2BTreeConfig GetTreeConfig() const
	{
		return _treeConfig;
	} 

	Blake2BConfig& GetConfig()
	{
		return _config;
	}

	Blake2BTreeConfig& GetTreeConfig()
	{
		return _treeConfig;
	}

	void SetConfig(const Blake2BConfig& value)
	{
		_config = value;
	}

	void SetTreeConfig(const Blake2BTreeConfig& value)
	{
		_treeConfig = value;
	}
	
	static Blake2XBConfig CreateBlake2XBConfig(const Blake2BConfig& config, const Blake2BTreeConfig& treeConfig)
	{
		return Blake2XBConfig(config, treeConfig);
	}

}; // end class 
