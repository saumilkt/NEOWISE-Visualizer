//
// Created by Saumil Thakore on 11/3/20.
//

#include "visualizer/json-app.h"
#include "core/json-deserialize.h"

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
namespace neowisejson {

  namespace visualizer {

    JsonApp::JsonApp() {
    }

    void JsonApp::setup() {
      ci::app::setWindowSize((int) kWindowSize,(int) kWindowSize);
      auto img = ci::loadImage(kFirstImagePath);
      mTex = ci::gl::Texture2d::create(img);
    }

    void JsonApp::keyDown(ci::app::KeyEvent event) {
      if (event.getCode() == ci::app::KeyEvent::KEY_0) {
        auto img = ci::loadImage(kFirstImagePath);
        mTex = ci::gl::Texture2d::create(img);
      } else if (event.getCode() == ci::app::KeyEvent::KEY_1) {
        auto img = ci::loadImage(kSecondImagePath);
        mTex = ci::gl::Texture2d::create(img);
      } else if (event.getCode() == ci::app::KeyEvent::KEY_2) {
        auto img = ci::loadImage(kThirdImagePath);
        mTex = ci::gl::Texture2d::create(img);
      } else if (event.getCode() == ci::app::KeyEvent::KEY_3) {
        auto img = ci::loadImage(kFourthImagePath);
        mTex = ci::gl::Texture2d::create(img);
      } else if (event.getCode() == ci::app::KeyEvent::KEY_4) {
        auto img = ci::loadImage(kFifthImagePath);
        mTex = ci::gl::Texture2d::create(img);
      } else if (event.getCode() == ci::app::KeyEvent::KEY_5) {
        auto img = ci::loadImage(kSixthImagePath);
        mTex = ci::gl::Texture2d::create(img);
      } else if (event.getCode() == ci::app::KeyEvent::KEY_ESCAPE) {
        quit();
      }
    }

    void JsonApp::draw() {
      // first, clear the screen
      ci::gl::clear(ci::Color::gray(0.1f));
      ci::gl::draw(mTex);

    }
  } // namespace visualizer

} // namespace idealgas