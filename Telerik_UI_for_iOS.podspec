Pod::Spec.new do |s|
  s.name             = 'Telerik_UI_for_iOS'
  s.version         = '0.0.1'
  s.license         =  { :type => 'BSD' }
  s.homepage         = 'http://www.telerik.com/ios-ui'
  s.authors         = { 'adi rome" => "adirome@seekingalpha.com' }
  s.summary         = 'A cocoa pod containing the TelerikUI framework.'
  s.source           = { :http => 'https://github.com/seekingalpha/Telerik_UI_for_iOS' }

  s.vendored_frameworks = 'TelerikUI.framework'
  s.source_files = 'Classes/*.{h,m}'
end
