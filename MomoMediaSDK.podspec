#
# Be sure to run `pod lib lint MLStreamPublisherFramework.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MomoMediaSDK'
  s.version          = '0.1.7' 
  s.summary          = 'A short description of MomoMediaSDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://www.baidu.com/'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'huanrusong@sina.com' => 'huanrusong@sina.com' }
  s.source           = { :git => 'https://github.com/cosmos33/MomoMediaSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'
  s.requires_arc = true
  s.static_framework = true
#  s.source_files = 'MLStreamPublisherFramework/Classes/**/*'
#  s.source_files = '**/Frameworks/*.{h,m}'
#  s.resources = '**/Frameworks/*.{nib}'
#  s.exclude_files = 'MLStreamPublisherFramework/Frameworks/*.framework/**/*'
  s.resources = 'Resources/*'
  s.vendored_frameworks = 'Frameworks/**/*.framework'
  s.vendored_libraries =  'Frameworks/**/*.{a}'
  s.libraries = 'stdc++', 'c++', 'xml2'
  s.framework = 'VideoToolbox' , 'Accelerate'
  # s.resource_bundles = {
  #   'MLStreamPublisherFramework' => ['MLStreamPublisherFramework/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
