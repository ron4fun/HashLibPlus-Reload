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

#include "Blake2SParams.h"
#include "../Interfaces/IHashInfo.h"

/// <summary>
/// <b>Blake2XSConfig</b> is used to configure _hash function parameters and
/// keying.
/// </summary>
class Blake2XSConfig final
{
private:
	Blake2SConfig _config;
	Blake2STreeConfig _treeConfig;

public:
	Blake2XSConfig() {}

	Blake2XSConfig(const Blake2SConfig& config, const Blake2STreeConfig& treeConfig)
	{
		_config = config;
		_treeConfig = treeConfig;
	}

	Blake2SConfig GetConfig() const
	{
		return _config;
	}

	Blake2STreeConfig GetTreeConfig() const
	{
		return _treeConfig;
	}

	Blake2SConfig& GetConfig() 
	{
		return _config;
	}

	Blake2STreeConfig& GetTreeConfig() 
	{
		return _treeConfig;
	}

	virtual void SetConfig(const Blake2SConfig& value)
	{
		_config = value;
	}

	virtual void SetTreeConfig(const Blake2STreeConfig& value)
	{
		_treeConfig = value;
	}

	virtual Blake2XSConfig Clone() const
	{
		return Blake2XSConfig(_config, _treeConfig);
	}

	static Blake2XSConfig CreateBlake2XSConfig(const Blake2SConfig& config, const Blake2STreeConfig& treeConfig)
	{
		return Blake2XSConfig(config, treeConfig);
	}

}; // end class 
