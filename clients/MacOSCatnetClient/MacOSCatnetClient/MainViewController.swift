//
//  MainViewController.swift
//  MacOSCatnetClient
//
//  Created by Milo Banks on 7/21/21.
//

import Cocoa

class MainViewController: NSViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do view setup here.
    }
    
    @IBAction func QuitButton(_ sender: Any) {
        let alert = NSAlert()
        alert.messageText = "Do you wish to stop CatNet?"
        alert.informativeText = "This will disconnect you from the network!"
        alert.alertStyle = .warning
        alert.addButton(withTitle: "No")
        alert.addButton(withTitle: "Yes")
        if alert.runModal() != .alertFirstButtonReturn {
            NSApplication.shared.terminate(self)
        }
    }
}

extension MainViewController {
    // MARK: Storyboard instantiation
    static func freshController() -> MainViewController {
        let storyboard = NSStoryboard(name: NSStoryboard.Name("Main"), bundle: nil)

        let identifier = NSStoryboard.SceneIdentifier("MainViewController")

        guard let viewcontroller = storyboard.instantiateController(withIdentifier: identifier) as? MainViewController else {
            fatalError("Why cant i find MainViewController? - Check Main.storyboard")
        }
        return viewcontroller
    }
}
