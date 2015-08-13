Pod::Spec.new do |s|
  s.name            = "Telerik_UI_for_iOS"
  s.version         = "0.0.1"
  s.homepage        = "http://www.telerik.com/ios-ui"

  s.license         = { :type => 'BSD' , :file => 'LICENSE' }

  s.authors         = { "John Smith" => "john.smith@telerik.com" }
  s.summary         = "A cocoa pod containing the TelerikUI framework."
  s.source          = {
  :git => "https://github.com/seekingalpha/Telerik_UI_for_iOS.git",
  :tag => "v0.0.1"
  }

  s.frameworks = 'TelerikUI'
  s.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => '${PODS_ROOT}/Telerik_UI_for_iOS' }

  s.source_files = 'Classes', 'Classes/**/*.{h,m}'
end
