//
//  SomeClass.h
//  AutoPtrTest
//
//  Created by Adrian on 3/28/11.
//  Copyright 2011 akosma software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmartPointer.h"

// typedef's are your best friend when playing with templates!
typedef ako::SmartPointer<NSMutableArray> Array;

@interface SomeClass : NSObject 
{
    
}

- (Array)createArrayWithCapacity:(NSInteger)count;
- (void)whateverYouWant;

@end
