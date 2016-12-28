// ECE4122/6122 RSA Encryption/Decryption assignment
// Fall Semester 2015

#include <iostream>
#include "RSA_Algorithm.h"
#include <gmpxx.h>


using namespace std;
//void KeyPairGen()
//mpz_class d[100]; mpz_class e[100]; mpz_class n[100]; 
mpz_class message; mpz_class M;
  // Instantiate the one and only RSA_Algorithm object
RSA_Algorithm RSA;

mpz_class messageGen(int sz){ 
  mpz_class plaintext= RSA.rng.get_z_bits(sz*2);
    while(plaintext > RSA.n){
      plaintext= RSA.rng.get_z_bits(sz*2);
    }
  return plaintext;
}

int main()
{

 int count=0; int c = 0;

  // Loop from sz = 32 to 1024 inclusive
  for(size_t i=32;i<=1024; i *= 2){
    //rng(gmp_randinit_default)
  // for each size choose 100 different key pairs
  for(int j = 0 ; j< 100; j++){
    //cerr<<" gen "<<endl;
    RSA.GenerateRandomKeyPair(i);
    RSA.PrintNDE();
    for(int k = 0; k < 100; k++) {
      //cerr<<" EN/DEC "<<endl;
      message=messageGen(i);
      RSA.PrintM(message);
      M=RSA.Encrypt(message);
      RSA.PrintC(M);
      M=RSA.Decrypt(M);
      c++;
      if(message==M) count++;
    //  cerr<< "count hit miss is  "<<count<<"/"<<c<<endl;
    }
    
  } 
   //cerr<< "count for now is "<<count<<endl;
  // For each key pair choose 100 differnt plaintext 
  // messages making sure it is smaller than n.
  // If not smaller then n then choose another
  // For eacm message encrypt it using the public key (n,e).
  // After encryption, decrypt the ciphertext using the private
  // key (n,d) and verify it matches the original message.
}
//cerr<< "count is "<<count<<endl;
}
  
