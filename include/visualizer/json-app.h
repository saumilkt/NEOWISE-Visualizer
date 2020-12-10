#ifndef INCLUDE_VISUALIZER_JSON_APP_H
#define INCLUDE_VISUALIZER_JSON_APP_H

#include  <string>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "../core/near-earth-object-explorer.h"
#include "../core/near-earth-object.h"
#include "../core/json-deserialize.h"
namespace neowisejson {

  namespace visualizer {
    using std::string;

    const string kFirstImagePath = "../../data/default-images/date_vs_magnitude.png";
    const string kSecondImagePath = "../../data/default-images/perihelion_vs_magnitude.png";
    const string kThirdImagePath = "../../data/default-images/period_vs_magnitude.png";
    const string kFourthImagePath = "../../data/default-images/perihelion_vs_moid..png";
    const string kFifthImagePath = "../../data/default-images/inclination_vs_perihelion.png";
    const string kSixthImagePath = "../../data/default-images/perihelion_vs_apohelion.png";

    class JsonApp : public ci::app::App {
    public:

      JsonApp();
      // Cinder will call 'setup' when the app is first created or initialized.
      void setup() override;

      // Cinder will call 'keyDown' when the user presses a key on the keyboard.
      // See also: keyUp.
      void keyDown(ci::app::KeyEvent event) override;

      // Cinder will call 'draw' each time the contents of the window need to be
      // redrawn.
      void draw() override;

    private:
      //Explorer explorer_ = Explorer(neowisejson::DeserializeDataset("data/json/neowise.json"));
      const size_t kWindowSize = 750;
      ci::gl::Texture2dRef mTex;

    };

  } // namespace visualizer

} // namespace neowisejson

#endif //INCLUDE_VISUALIZER_JSON_APP_H
