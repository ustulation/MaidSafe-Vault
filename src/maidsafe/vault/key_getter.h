/***************************************************************************************************
 *  Copyright 2012 MaidSafe.net limited                                                            *
 *                                                                                                 *
 *  The following source code is property of MaidSafe.net limited and is not meant for external    *
 *  use.  The use of this code is governed by the licence file licence.txt found in the root of    *
 *  this directory and also on www.maidsafe.net.                                                   *
 *                                                                                                 *
 *  You are not free to copy, amend or otherwise use this source code without the explicit         *
 *  written permission of the board of directors of MaidSafe.net.                                  *
 **************************************************************************************************/

#ifndef MAIDSAFE_VAULT_KEY_GETTER_H_
#define MAIDSAFE_VAULT_KEY_GETTER_H_

#include <string>

#include "maidsafe/routing/api_config.h"



namespace maidsafe {

namespace routing { class Routing; }

namespace vault {

class KeyGetter {
 public:
  KeyGetter(routing::Routing& routing);
  ~KeyGetter();
  void HandleGetKey(const NodeId& node_id, const routing::GivePublicKeyFunctor& give_key);

 private:
  routing::Routing& routing_;
};

}  // namespace vault

}  // namespace maidsafe

#endif  // MAIDSAFE_VAULT_KEY_GETTER_H_