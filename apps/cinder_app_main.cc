#include <visualizer/json-app.h>

using neowisejson::visualizer::JsonApp;

void prepareSettings(JsonApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(JsonApp, ci::app::RendererGl, prepareSettings);
