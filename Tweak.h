#import <UIKit/UIKit.h>
#include <dlfcn.h>

@interface NCNotificationRequest : NSObject
@end

@interface GRPManager : NSObject
@property (nonatomic, weak) NCNotificationRequest *latestRequest;
+(id)sharedInstance;

-(void)showNotificationRequest:(id)req;
-(void)hideNotificationRequests:(id)reqs;
-(void)hideAllNotificationRequests;
-(void)hideAllNotificationRequestsExcept:(id)notification;
-(void)revealNotificationHistory:(BOOL)revealed;
@end

@interface GRPView : UIView
@property (nonatomic, retain) UICollectionView *collectionView;;
@property (nonatomic, retain) NSString *selectedBundleIdentifier;
@property (nonatomic, assign) BOOL showingLatestRequest;

-(void)refresh;
-(void)reset;
@end
