/* Copyright 2012 MaidSafe.net limited

This MaidSafe Software is licensed under the MaidSafe.net Commercial License, version 1.0 or later,
and The General Public License (GPL), version 3. By contributing code to this project You agree to
the terms laid out in the MaidSafe Contributor Agreement, version 1.0, found in the root directory
of this project at LICENSE, COPYING and CONTRIBUTOR respectively and also available at:

http://www.novinet.com/license

Unless required by applicable law or agreed to in writing, software distributed under the License is
distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied. See the License for the specific language governing permissions and limitations under the
License.
*/

#ifndef MAIDSAFE_VAULT_MAID_MANAGER_VALUE_H_
#define MAIDSAFE_VAULT_MAID_MANAGER_VALUE_H_

#include <cstdint>
#include <set>
#include <vector>

#include "maidsafe/common/types.h"
#include "maidsafe/vault/data_manager/data_manager.pb.h"
#include "maidsafe/vault/types.h"

namespace maidsafe {

namespace vault {

class MaidManagerValue {
  typedef TaggedValue<NonEmptyString, struct SerialisedMaidManagerValueTag> serialised_type;
  explicit MaidManagerValue(const serialised_type& serialised_metadata_value);
  explicit MaidManagerValue();
  serialised_type Serialise() const;

  void Put(const int32_t& cost);  // kPut
  void Delete(const int32_t& cost);  // kDelete

  friend bool operator==(const MaidManagerValue& lhs, const MaidManagerValue& rhs);

 private:
  int32_t count_;
  int32_t cost_;
};

bool operator==(const MaidManagerValue& lhs, const MaidManagerValue& rhs);

}  // namespace vault

}  // namespace maidsafe


#endif  // MAIDSAFE_VAULT_MAID_MANAGER_VALUE_H_