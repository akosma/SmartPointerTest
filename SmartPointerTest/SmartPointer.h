//
//  SmartPointer.h
//  AutoPtrTest
//
//  Created by Adrian on 3/28/11.
//  Copyright 2011 akosma software. All rights reserved.
//

namespace ako 
{
    /**
     This class is a simple C++ smart pointer around an Objective-C object.
     */
    template <class T>
    class SmartPointer 
    {
    public:
        
        // Constructors and destructors
        SmartPointer(T*);
        SmartPointer(const SmartPointer&);
        SmartPointer& operator=(const SmartPointer&);
        SmartPointer& operator=(T* object);
        virtual ~SmartPointer();
        
        // Methods to get access to the underlying Objective-C object
        T* operator*() const;
        T* operator()() const;
        T* get() const;
        
        // Static methods
        static SmartPointer<T> create();

    private:
        T* _pointee; //< Owned by the current instance.
    };

    /**
     Static method used to create a new object
     using alloc/init and then returning the auto ptr.
     */
    template <class T>
    SmartPointer<T> SmartPointer<T>::create()
    {
        T* obj = [[T alloc] init];
        SmartPointer<T> autoObj = SmartPointer<T>(obj);
        return autoObj;
    }

    /**
     Constructor.
     */
    template <class T>
    SmartPointer<T>::SmartPointer(T* pointee)
    : _pointee(pointee)
    {
    }

    /**
     Copy constructor.
     Extremely important, because SmartPointer objects are
     copied from stack frame to stack frame, always pointing
     to the same object on the heap.
     */
    template <class T>
    SmartPointer<T>::SmartPointer(const SmartPointer& rhs)
    : _pointee(rhs._pointee)
    {
    }

    /**
     Assignment operator.
     */
    template <class T>
    SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer& rhs)
    {
        if (this != &rhs)
        {
            _pointee = rhs._pointee;
        }
        return *this;
    }
    
    /**
     Assignment operator to Objective-C types.
     The idea of this syntax for assignment comes from 
     https://github.com/philsquared/OCPtr
     */
    template <class T>
    SmartPointer<T>& SmartPointer<T>::operator=(T* object)
    {
        _pointee = object;
        return *this;
    }
    
    /**
     Destructor.
     The important part of the class is here; when a C++ object
     in the stack goes out of scope, its destructor is called;
     hence, we call "release" on the owned object.
     */
    template <class T>
    SmartPointer<T>::~SmartPointer()
    {
        [_pointee release];
    }

    /**
     Returns a pointer to the underlying Objective-C object.
     */
    template <class T>
    T* SmartPointer<T>::operator*() const
    {
        return _pointee;
    }

    /**
     Returns a pointer to the underlying Objective-C object.
     */
    template <class T>
    T* SmartPointer<T>::operator()() const
    {
        return _pointee;
    }

    /**
     Returns a pointer to the underlying Objective-C object.
     */
    template <class T>
    T* SmartPointer<T>::get() const
    {
        return _pointee;
    }
}
