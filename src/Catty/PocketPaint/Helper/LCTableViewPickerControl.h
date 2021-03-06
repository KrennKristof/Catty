//
//  LCTableViewPickerControl.h
//  InsurancePig
//
//  Created by Leo Chang on 10/21/13.
//  Copyright (c) 2013 Good-idea Consunting Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kAnimationDuration 0.4

enum ActionType {
  brush,
  eraser,
  resize,
  pipette,
  mirror,
  image,
  line,
  rectangle,
  ellipse,
  rotate,
  stamp,
  fillTool,
  zoom,
  pointer,
  text
};
typedef enum ActionType actionType;


@class LCTableViewPickerControl;
@protocol LCItemPickerDelegate <NSObject>

- (void)selectControl:(LCTableViewPickerControl*)view didSelectWithItem:(id)item;
- (void)selectControl:(LCTableViewPickerControl *)view didCancelWithItem:(id)item;

@end



@interface LCTableViewPickerControl : UIView <UITableViewDataSource, UITableViewDelegate>

@property (weak) id <LCItemPickerDelegate> delegate;
//@property (nonatomic, assign) NSInteger tag; // leads to warning, because this property is already implemented in superclass (UIView)
@property (nonatomic, strong) NSString *key;
@property (nonatomic, assign) NSInteger height;
- (id)initWithFrame:(CGRect)frame title:(NSString*)title value:(actionType)value items:(NSArray*)array screenHeight:(NSInteger)screenHeight navBarOffset:(NSInteger)navbarOffset;

- (void)showInView:(UIView*)view;
- (void)dismiss;

@end
