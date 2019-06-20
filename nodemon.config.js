const nodemonConfig = {
    "watch": [
        "./src/",
        "./test/*.ts",
        "./keybindings/**/*.json"
    ],
    "ext": ["ts","json"],
    "ignore": [
        "dist",
        ".cache",
        ".git",
        "src/**/*.spec.ts",
        "**/node_modules/",
        "migrations",
        "**/.sqlite"
    ],
    "exec": "ts-node -r tsconfig-paths/register"
}

module.exports = nodemonConfig;