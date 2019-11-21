
export const hotkeySchemas = {

    firefox: {
        commands: {
            _execute_browser_action: {
                suggested_key: {
                    default: "Ctrl+Shift+K"
                },
                description: "Show the 'Quick Bookmark To Folder' popup"
            }
        }
    },

    vscode: {
        key: string;
        arg: string;
        command: string;
        when?: string;
    },

    autohotkey: {
        key: string;
        arg: string;
        command: string;
        when?: string;
    },




}