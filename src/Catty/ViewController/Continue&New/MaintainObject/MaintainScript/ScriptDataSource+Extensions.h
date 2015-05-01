/**
 *  Copyright (C) 2010-2015 The Catrobat Team
 *  (http://developer.catrobat.org/credits)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  An additional term exception under section 7 of the GNU Affero
 *  General Public License, version 3, is available at
 *  (http://developer.catrobat.org/license_additional_term)
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses/.
 */

#import "ScriptDataSource.h"


@interface ScriptDataSource (Extensions)

- (void)addBricks:(NSArray *)bricks atIndexPath:(NSIndexPath *)atIndexPath;

- (void)addScript:(Script *)script toSection:(NSInteger)section;

// Removes complete section.
- (void)removeScriptsAtSections:(NSIndexSet *)sections;

// Remove single brick.
- (void)removeBrickAtIndexPath:(NSIndexPath *)indexPath;

- (void)copyBrickAtIndexPath:(NSIndexPath *)atIndexPath;

// Script with brick list array.
- (id)itemAtIndexPath:(NSIndexPath *)indexPath;

// Returns indexpath for equal items (script bricks or none-script bricks).
- (NSArray *)indexPathsForItem:(id)item;

- (NSArray *)brickListInScriptAtIndexPath:(NSIndexPath *)indexPath;

// Returns nil if Scriptbrick (index 0 in section).
- (Brick *)brickInScriptAtIndexPath:(NSIndexPath *)indexPath;

- (Script *)scriptAtSection:(NSUInteger)section;

- (BOOL)isSectionAtIndexPathValidScript:(NSIndexPath *)indexPath;

/// Returns linked loop/condition bricks or just one single brick.
- (NSArray *)linkedBricksForBrick:(kBrickType)brickType;

@end