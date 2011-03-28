//
//  SomeClass.m
//  AutoPtrTest
//
//  Created by Adrian on 3/28/11.
//  Copyright 2011 akosma software. All rights reserved.
//

#import "SomeClass.h"


@implementation SomeClass

- (void)dealloc
{
    // This text will appear on the console when the
    // SmartPointer surrounding this instance will go out of scope.
    NSLog(@"[SomeClass dealloc]");
    [super dealloc];
}

- (Array)createArrayWithCapacity:(NSInteger)count
{
    NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:count];
    return Array(array);
}

- (void)whateverYouWant
{
}

@end
