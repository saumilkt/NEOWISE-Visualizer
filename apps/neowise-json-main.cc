//
// Created by Saumil Thakore on 11/17/20.
//
#include <iostream>
#include "core/json-deserialize.h"
#include "core/near-earth-object.h"
#include "core/near-earth-object-explorer.h"

int main(int argc, char* argv[]) {
  neowisejson::Explorer explorer = (neowisejson::DeserializeDataset("data/main/neowise.json"));
  return 0;
}