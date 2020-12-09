//
// Created by Saumil Thakore on 11/3/20.
//

#include "visualizer/json-app.h"
#include "core/json-deserialize.h"
namespace neowisejson {

  namespace visualizer {

    JsonApp::JsonApp() {
    }

    void JsonApp::setup() {
      ci::app::setWindowSize((int) kWindowSize,(int) kWindowSize);
    }

    void JsonApp::draw() {
      // first, clear the screen
      ci::gl::clear(ci::Color::gray(0.1f));
    }
  } // namespace visualizer

} // namespace idealgas