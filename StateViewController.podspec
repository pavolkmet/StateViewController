Pod::Spec.new do |s|

  s.name              = 'StateViewController'
  s.version           = '0.1.0'
  s.summary           = 'Small extension which handle loading, empty and error states of view controller.'

  s.description       = <<-DESC
  A view controller extension which presents `UIView` for loading, error and empty states.
                   DESC

  s.homepage          = 'https://github.com/GoodRequest/StateViewController.git'
  s.license           = { :type => 'MIT', :file => 'LICENSE' }
  s.author            = { 'Pavol Kmet' => 'pavol.kmet@goodrequest.com' }
  s.social_media_url  = 'https://twitter.com/goodrequestcom'

  s.ios.deployment_target = '9.0'

  s.source            = { :git => 'https://github.com/GoodRequest/StateViewController.git', :tag => s.version.to_s }
  s.source_files      = 'Sources/*.{h,m}'
  s.framework         = 'UIKit'
  s.requires_arc      = true

end
