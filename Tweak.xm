#import "Tweak.h"

%hook GRPView
  -(void)reset {
    %orig;
    GRPManager *manager = [%c(GRPManager) sharedInstance];
    self.showingLatestRequest = NO;
    self.selectedBundleIdentifier = nil;

    if (manager.latestRequest) {
      [manager showNotificationRequest:manager.latestRequest];
      [manager hideAllNotificationRequestsExcept:manager.latestRequest];
      self.showingLatestRequest = YES;
    } else {
      [manager hideAllNotificationRequests];
    }
    [self.collectionView reloadSections:[NSIndexSet indexSetWithIndex:0]];
    [manager revealNotificationHistory:false];
  }
%end

%ctor {
  dlopen("/Library/MobileSubstrate/DynamicLibraries/Grupi.dylib", RTLD_NOW);
}
