//
//  main.m
//  AutoPtrTest
//
//  Created by Adrian on 3/28/11.
//  Copyright 2011 akosma software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmartPointer.h"
#import "SomeClass.h"

using namespace ako;

typedef SmartPointer<SomeClass> SomeType;

int main (int argc, const char * argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    
    // It is usually recommended to avoid allocating autoreleased
    // instances in loops, hence this example.
    for (NSInteger index = 0; index < 10; ++index)
    {
        // A SmartPointer around an NSObject
        SmartPointer<NSObject> obj = SmartPointer<NSObject>::create();

        // SomeType is a typedef (see above)
        SomeType someObj = SomeType::create();
        
        // You can get access to the underlying Objective-C object
        // using "*", ".get()" or "()"; they all return the same pointer.
        // And once you have it, it's a normal Objective-C pointer
        // you can send messages to:
        SmartPointer<NSMutableArray> array = [*someObj createArrayWithCapacity:5];
        
        // Here a SmartPointer around an NSNumber
        NSNumber *value = [[NSNumber alloc] initWithInt:1424];
        SmartPointer<NSNumber> number = SmartPointer<NSNumber>(value);
        
        // Playing with the array we got above, just to show it's a normal object
        [array.get() addObject:@"test1"];
        [*array      addObject:@"test2"];
        [*array      addObject:number()];
        [array()     addObject:*obj];

        // After this NSLog call, in the console you should see 
        // "[SomeClass dealloc]" which is printed when the SmartPointer goes
        // out of scope, sending the release message on the underlying pointer.
        NSLog(@"array %@", *array);
    }

    [pool release];
    return 0;
}
