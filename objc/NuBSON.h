/*!
@header NuBSON.h
@discussion Declarations for the NuBSON component.
@copyright Copyright (c) 2010 Radtastical, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#import <Foundation/Foundation.h>
#import "BSONObjectID.h"
#import "bson.h"

/*!
   @class NuBSON
   @abstract A BSON serializer and deserializer.
   @discussion BSON is the wire format used to communicate with MongoDB.
 */
@interface NuBSON : NSObject
{
    @public
    bson bsonValue;
}
/*! Create a BSON representation from serialized NSData. */
+ (NuBSON *) bsonWithData:(NSData *) data;
/*! Create an array of BSON objects from serialized NSData. */
+ (NSMutableArray *) bsonArrayWithData:(NSData *) data;

/*! Create a BSON representation of a dictionary object. */
+ (NuBSON *) bsonWithDictionary:(NSDictionary *) dict;
/*! Create a BSON representation from a Nu list. */
+ (NuBSON *) bsonWithList:(id) cell;

/*! Create a BSON representation from serialized NSData. */
- (NuBSON *) initWithData:(NSData *) data;
/*! Create a BSON representation of a dictionary object. */
- (NuBSON *) initWithDictionary:(NSDictionary *) dict;
/*! Create a BSON representation from a Nu list. */
- (NuBSON *) initWithList:(id) cell;

/*! Return an NSData representation of the BSON object. */
- (NSData *) dataRepresentation;
/*! Return a dictionary equivalent of a BSON object. */
- (NSMutableDictionary *) dictionaryValue;

/*! Return an array containing all the top-level keys in the BSON object. */
- (NSArray *) allKeys;

/*! Return a named top-level element of the BSON object. */
- (id) objectForKey:(NSString *) key;
/*! Return a named element of the BSON object. */
- (id) objectForKeyPath:(NSString *) keypath;
@end

@interface NuBSONBuffer : NSObject 
{
	bson_buffer bb;	
}

- (id) init;
- (NuBSON *) bsonValue;
- (void) addObject:(id) object withKey:(id) key;
@end

bson *bson_for_object(id object); // used in NuMongoDB

@interface NuBSONComparator : NSObject
{
    NuBSON *specification;
}
/*! Create a new and comparator for the given BSON specification. */
+ (NuBSONComparator *) comparatorWithBSONSpecification:(NuBSON *) s;
/*! Compare BSON data using the associated specification. */
- (int) compareDataAtAddress:(const void *) aptr withSize:(int) asiz withDataAtAddress:(const void *) bptr withSize:(int) bsiz;

@end


// deprecated convenience categories
@interface NSData (NuBSON)
- (NSMutableDictionary *) BSONValue;
@end

@interface NSDictionary (NuBSON)
- (NSData *) BSONRepresentation;
@end