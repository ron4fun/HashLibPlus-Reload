HashLibPlus-Reload [![License](http://img.shields.io/badge/license-MPL2-blue.svg)](https://github.com/Ron4fun/HashLibPlus/blob/master/LICENSE)
====

HashLibPlus is a recommended C++11 hashing library that provides a fluent interface for computing hashes and checksums of strings, files, streams, bytearrays and untyped data to mention but a few.

It also supports **Incremental Hashing**, **Cloning**, **NullDigest**.

Available Algorithms
----------------------------------------

 ### Hashes
----------------------------------------
##### Cyclic Redundancy Checks

* `All CRC Variants from CRC3 to CRC64` :heavy_check_mark:

##### Checksums

* `Adler32` :heavy_check_mark:

##### Non-Cryptographic Hash Functions 
----------------------------------------

###### 32 bit hashes

* `AP` `BKDR` `Bernstein` `Bernstein1` `DEK` `DJB` `ELF` `FNV` :heavy_check_mark:

* `FNV1a` `JS` `Jenkins3` `Murmur2` `MurmurHash3_x86_32` `OneAtTime` :heavy_check_mark:

*  `PJW` `RS` `Rotating` `SDBM` `ShiftAndXor` `SuperFast` `XXHash32` :heavy_check_mark:

###### 64 bit hashes

* `FNV64` `FNV1a64` `Murmur2_64` `SipHash64_2_4` `XXHash64` :heavy_check_mark:

###### 128 bit hashes

* `MurmurHash3_x86_128` `MurmurHash3_x64_128` `SipHash128_2_4` :heavy_check_mark:

##### Cryptographic Hash Functions 
----------------------------------------

 * `MD2` :heavy_check_mark:

 * `MD4` :heavy_check_mark:

 * `MD5` :heavy_check_mark:

 * `SHA-0` :heavy_check_mark:

 * `SHA-1` :heavy_check_mark:

 * `SHA-2 (224, 256, 384, 512, 512-224, 512-256)` :heavy_check_mark:

 * `GOST 34.11-94` :heavy_check_mark:

 * `GOST R 34.11-2012 (AKA Streebog) (256, 512)` :heavy_check_mark:
 
 * `Grindahl (256, 512)` :heavy_check_mark:
 
 * `HAS160` :heavy_check_mark:

 * `RIPEMD (128, 256, 256, 320)` :heavy_check_mark:

 * `Tiger (128, 160, 192 (Rounds 3, 4, 5))` :heavy_check_mark:

 * `Tiger2 (128, 160, 192 (Rounds 3, 4, 5))` :heavy_check_mark:
 
 * `Snefru (128, 256)` :heavy_check_mark:
 
 * `Haval (128, 160, 192, 224, 256 (Rounds 3, 4, 5))` :heavy_check_mark:
 
 * `Panama` :heavy_check_mark:
 
 * `RadioGatun (RadioGatun32, RadioGatun64)` :heavy_check_mark:

 * `WhirlPool` :heavy_check_mark:

 * `Blake2B (160, 256, 384, 512)` :heavy_check_mark:
 
 * `Blake2S (128, 160, 224, 256)` :heavy_check_mark:

 * `SHA-3 (224, 256, 384, 512)` :heavy_check_mark:
 
 * `Keccak (224, 256, 288, 384, 512)` :heavy_check_mark:
 
 * `Blake2BP` :heavy_check_mark:

 * `Blake2SP` :heavy_check_mark:

 * `Blake3` :heavy_check_mark:

### Key Derivation Functions
----------------------------------------

###### Password Hashing Schemes (Password Based Key Derivation Functions)

----------------------------------------

* `PBKDF2` :heavy_check_mark:
 
* `Argon2 (2i, 2d and 2id variants)` :heavy_check_mark:

* `Scrypt` :heavy_check_mark:

### MAC
----------------------------------------

* `HMAC (all supported hashes)` :heavy_check_mark:

* `KMAC (KMAC128, KMAC256)` :heavy_check_mark:

* `Blake2MAC (Blake2BMAC, Blake2SMAC)` :heavy_check_mark:

### XOF (Extendable Output Function)
----------------------------------------

* `Shake (Shake-128, Shake-256)` :heavy_check_mark:

* `CShake (CShake-128, CShake-256)` :heavy_check_mark:

* `Blake2X (Blake2XS, Blake2XB)` :heavy_check_mark:

* `KMACXOF (KMAC128XOF, KMAC256XOF)` :heavy_check_mark:

* `Blake3XOF` :heavy_check_mark:

### Usage Examples
----------------------------------------


```c++
#include "Base/HashFactory.h"

int main() 
{
    IHash hash = HashFactory::Crypto::CreateMD5();
		
    IHash clone = hash->Clone();

    IHMAC hmac = HashFactory::HMAC::CreateHMAC(hash);
    hmac->SetKey(Converters::ConvertStringToBytes("password"));

    IHashResult Result1 = hash->ComputeString("Hash");
    IHashResult Result2 = hmac->ComputeString("Hash");
	
    bool check = Result1->CompareTo(Result2);
    
    return 0;
}
```

How to build library
----------------------------------------

**Note: [catch2](https://github.com/catchorg/Catch2) library was used as the test framework in the `HashLibPlus.Test` project.** 


**1. Build the `HashLibPlus-Reloaded` project firstly.**

**2. Drag and drop the built HashLibPlus-Reload Release `*.obj` files (except for `HashLibPlus.obj`) into HashLibPlus.Test project in `Visual Studio` (to avoid link issues) then build.**

* HashLibPlus.exe
----------------------------------------
This executable displays a benchmark test analysis of the compiled code speed with regards to your C.P.U capability. 

* HashLibPlus.Test.exe
----------------------------------------
This executable hooks into [catch2](https://github.com/catchorg/Catch2) process to allow for detailed test results, and other command line options that *catch2* supports for those that wish to pass values to *catch2* interface.

### Other Implementations
----------------------------------------

If you want implementations in other languages, you can check out these

* [SharpHash](https://github.com/ron4fun/SharpHash) by Mbadiwe Nnaemeka Ronald
* [HashLib4Pascal](https://github.com/Xor-el/HashLib4Pascal) by Ugochukwu Mmaduekwe

### Tip Jar
----------------------------------------

* :dollar: **Bitcoin**: `1Mcci95WffSJnV6PsYG7KD1af1gDfUvLe6`
