//**********************************************************************************
//EncryptPad Copyright 2016 Evgeny Pokhilko 
//<http://www.evpo.net/encryptpad>
//
//This file is part of EncryptPad
//
//EncryptPad is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 2 of the License, or
//(at your option) any later version.
//
//EncryptPad is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with EncryptPad.  If not, see <http://www.gnu.org/licenses/>.
//**********************************************************************************
#pragma once

#include <memory>
#include <vector>
#include "botan.h"
#include "encryptmsg/algo_spec.h"
#include "packet_typedef.h"
#include "encryptmsg/emsg_types.h"

namespace EncryptPad
{

    struct KeyRecord
    {
        std::unique_ptr<EncryptMsg::EncryptionKey> key;
        EncryptMsg::Salt salt;
        int iterations;

        bool used;

        bool IsEmpty() const
        {
            return key->length() == 0;
        }

        KeyRecord():
            key(std::unique_ptr<EncryptMsg::EncryptionKey>(new EncryptMsg::EncryptionKey()))
        {
        }
    };

    const int kDefaultKeyCount = 5;
    const int kSaltSize = 8;


    // The service maintains correspondence between key and its salt
    // It allows not to store the passphrase in memory and load and save files repeatedly 
    // without asking the passphrase again
    class KeyService
    {
        typedef std::shared_ptr<KeyRecord> KeyRecordPtr;

        int key_count_;

        EncryptMsg::HashAlgo hash_algo_;
        int key_size_;

        KeyRecord empty_record_;
        std::vector<KeyRecordPtr> key_records_;

    public:
        KeyService(int key_count = kDefaultKeyCount);

        int get_key_count() const
        {
            return key_count_;
        }

        void set_key_count(int key_count);

        int get_key_size() const
        {
            return key_size_;
        }

        EncryptMsg::HashAlgo get_hash_algo() const
        {
            return hash_algo_;
        }

        bool IsPassphraseSet() const
        {
            return key_records_.size() != 0;
        }

        // Returns true if there are unused keys
        bool UnusedKeysExist() const;

        int UnusedKeysCount() const;

        // Clears all keys
        void Clear()
        {
            key_records_.clear();
        }

        // Clears all previous keys and generates new keys from passphrase with different salts, 
        // one of them has the salt from the parameter.
        // Returns the key with the salt from the parameter. This key is also marked as used.
        const KeyRecord &ChangePassphrase(const std::string &passphrase, EncryptMsg::HashAlgo hash_algo, unsigned key_size,
                int iterations, EncryptMsg::Salt salt = EncryptMsg::Salt());

        // Returns a key generated from the current passphrase and marks it as used so it is not used for saving again. 
        // When all key_count_ keys have been used, it returns an empty record and all keys are deleted.
        const KeyRecord &GetKeyForSaving();

        // Check if we have this key in the storage
        // If we don't have it, we need to regenerate new keys. Call ChangePassphrase.
        const KeyRecord &GetKeyForLoading(const std::vector<uint8_t> &salt, int iterations, EncryptMsg::HashAlgo hash_algo) const;

    private:
        const KeyRecord &EmptyRecord() const;
    };
}
