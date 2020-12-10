//
// Created by Saumil Thakore on 11/17/20.
//
#include <iostream>
#include "core/json-deserialize.h"
#include "core/near-earth-object.h"
#include "core/near-earth-object-explorer.h"

int main() {
  neowisejson::Explorer explorer = (neowisejson::DeserializeDataset("data/json/neowise.json"));
  return 0;
}