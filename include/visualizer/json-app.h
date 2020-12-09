#ifndef INCLUDE_VISUALIZER_JSON_APP_H
#define INCLUDE_VISUALIZER_JSON_APP_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "../core/near-earth-object-explorer.h"
#include "../core/near-earth-object.h"
#include "../core/json-deserialize.h"
namespace neowisejson {

  namespace visualizer {

    class JsonApp : public ci::app::App {
    public:

      JsonApp();
      // Cinder will call 'setup' when the app is first created or initialized.
      void setup() override;


      // Cinder will call 'draw' each time the contents of the window need to be
      // redrawn.
      void draw() override;

    private:
      //Explorer explorer_ = Explorer(neowisejson::DeserializeDataset("data/main/neowise.json"));
      const size_t kWindowSize = 750;

    };

  } // namespace visualizer

} // namespace neowisejson

#endif //INCLUDE_VISUALIZER_JSON_APP_H
