/*
 *
 * BitcoinLikeKeychain
 * ledger-core
 *
 * Created by Pierre Pollastri on 17/01/2017.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
#ifndef LEDGER_CORE_BITCOINLIKEKEYCHAIN_HPP
#define LEDGER_CORE_BITCOINLIKEKEYCHAIN_HPP

#include "../../../api/BitcoinLikeCurrencyDescription.hpp"
#include "../../../bitcoin/BitcoinLikeExtendedPublicKey.hpp"
#include <string>
#include <vector>
#include "../../../utils/Option.hpp"
#include "../../../preferences/Preferences.hpp"
#include "../../../api/Configuration.hpp"

namespace ledger {
    namespace core {

        class BitcoinLikeKeychain {
        public:
            enum KeyPurpose {
                RECEIVE, CHANGE
            };

        public:
            BitcoinLikeKeychain(
                    const std::shared_ptr<api::Configuration> configuration,
                    const api::BitcoinLikeNetworkParameters& params,
                    int account,
                    const std::shared_ptr<api::BitcoinLikeExtendedPublicKey>& xpub,
                    const std::shared_ptr<Preferences> preferences);

            virtual bool markAsUsed(const std::vector<std::string>& addresses);
            virtual bool markAsUsed(const std::string& address) = 0;

            virtual std::vector<std::string> getAllObservableAddresses(uint32_t from, uint32_t to)  = 0;
            virtual std::vector<std::string> getAllObservableAddresses(KeyPurpose purpose, uint32_t from, uint32_t to) = 0;

            virtual std::string getFreshAddress(KeyPurpose purpose) = 0;
            virtual std::vector<std::string> getFreshAddresses(KeyPurpose purpose, size_t n) = 0;

            virtual Option<KeyPurpose> getAddressPurpose(const std::string& address) const = 0;
            virtual Option<std::string> getAddressDerivationPath(const std::string& address) const = 0;
            virtual bool isEmpty() const = 0;

            int getAccountIndex() const;
            const api::BitcoinLikeNetworkParameters& getNetworkParameters() const;
            std::shared_ptr<api::BitcoinLikeExtendedPublicKey> getExtendedPublicKey() const;
            std::shared_ptr<api::Configuration> getConfiguration() const;

        protected:
            std::shared_ptr<Preferences> getPreferences() const;

        private:
            const api::BitcoinLikeNetworkParameters& _params;
            std::shared_ptr<api::BitcoinLikeExtendedPublicKey> _xpub;
            int _account;
            std::shared_ptr<Preferences> _preferences;
            std::shared_ptr<api::Configuration> _configuration;
        };
    }
}

#endif //LEDGER_CORE_BITCOINLIKEKEYCHAIN_HPP