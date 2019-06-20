const path = require("path");
const baseConfig = require("./config/jest.node.config.js");

module.exports = {
    globals: {
        "ts-jest": {
            tsConfig: "./tsconfig.json", //path.resolve(__dirname, "/tsconfig.test.json"),
            diagnostics: true //
        }
      },
      /*transform: {
        "^.+\\.(tsx?)$": "<rootDir>/config/jest-preprocessor.js"
      },c
    moduleNameMapper: {
      "@app/(.*)": `<rootDir>/src/app/$1`
    },*/
    ...baseConfig
};