/**
 *  Copyright (C) 2010-2020 The Catrobat Team
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

import Foundation

@objc extension CatrobatTableViewController {

    func openURL(url: URL) {
        self.openURL(url: url, storeProjectDownloader: StoreProjectDownloader())
    }

    @nonobjc func openURL(url: URL, storeProjectDownloader: StoreProjectDownloaderProtocol) {
        guard let projectId = CatrobatTableViewController.catrobatProjectIdFromURL(url: url) else {
            Util.alert(withText: kLocalizedInvalidURLGiven)
            return
        }
        storeProjectDownloader.fetchProjectDetails(for: projectId, completion: {project, error in
            guard error == nil else {
                Util.alert(withText: kLocalizedUnableToLoadProject)
                return
            }
            guard let storeProject = project else {
                Util.alert(withText: kLocalizedInvalidZip)
                return
            }
            let catrobatProject = storeProject.toCatrobatProject()

            let storyboard = UIStoryboard(name: "iPhone", bundle: nil)
            guard let viewController = storyboard.instantiateViewController(withIdentifier: "ProjectDetailStoreViewController") as? ProjectDetailStoreViewController else { return }
            viewController.project = catrobatProject
            self.navigationController?.pushViewController(viewController, animated: true)
        })
    }

    static func catrobatProjectIdFromURL(url: URL) -> String? {
        let pathComponents = url.pathComponents
        guard pathComponents.count >= 4 else {
            return nil
        }
        switch pathComponents[2] {
        case "project":
            return pathComponents[3]
        case "download":
            return String(pathComponents[3].dropLast(9))
        default:
            return nil
        }
    }
}
