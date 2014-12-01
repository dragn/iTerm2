//
//  iTermPasteSpecialViewController.h
//  iTerm2
//
//  Created by George Nachman on 11/30/14.
//
//

#import <Cocoa/Cocoa.h>

// These values correspond to cell tags on the matrix.
NS_ENUM(NSInteger, iTermTabTransformTags) {
    kTabTransformNone = 0,
    kTabTransformConvertToSpaces = 1,
    kTabTransformEscapeWithCtrlZ = 2
};

@protocol iTermPasteSpecialViewControllerDelegate <NSObject>

- (void)pasteSpecialViewSpeedDidChange;
- (void)pasteSpecialTransformDidChange;

@end

@interface iTermPasteSpecialViewController : NSViewController

@property(nonatomic, assign) int chunkSize;
@property(nonatomic, assign) NSTimeInterval delayBetweenChunks;
@property(nonatomic, assign) id<iTermPasteSpecialViewControllerDelegate> delegate;

@property(nonatomic, assign) int numberOfSpacesPerTab;
@property(nonatomic, assign, getter=areTabTransformsEnabled) BOOL enableTabTransforms;
@property(nonatomic, assign) NSInteger selectedTabTransform;
@property(nonatomic, assign, getter=isConvertNewlinesEnabled) BOOL enableConvertNewlines;
@property(nonatomic, assign) BOOL shouldConvertNewlines;
@property(nonatomic, assign, getter=isEscapeShellCharsWithBackslashEnabled) BOOL enableEscapeShellCharsWithBackslash;
@property(nonatomic, assign) BOOL shouldEscapeShellCharsWithBackslash;
@property(nonatomic, assign, getter=isRemoveControlCodesEnabled) BOOL enableRemoveControlCodes;
@property(nonatomic, assign) BOOL shouldRemoveControlCodes;
@property(nonatomic, assign, getter=isBracketedPasteEnabled) BOOL enableBracketedPaste;
@property(nonatomic, assign) BOOL shouldUseBracketedPasteMode;
@property(nonatomic, assign, getter=isBase64Enabled) BOOL enableBase64;
@property(nonatomic, assign) BOOL shouldBase64Encode;

- (NSString *)descriptionForDuration:(NSTimeInterval)duration;

@end
