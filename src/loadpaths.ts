import * as TsconfigPaths from 'tsconfig-paths';
import {relative,join,dirname} from 'path';
 
const root = process.cwd(); //'/home/jm/Projects/Apps/HotkeyManager';
 const cu = {
  baseUrl: '.', 
  paths: {
    "*": [ "*" ],
    "@/*" : [ "./src/*"],
    "@Modules/*" : [ relative(root, '/home/jm/Projects/Modules/*') ],
    },
}
console.log(cu);

const cleanup = TsconfigPaths.register(cu);
//cleanup();

  /* 

// Load tsconfig
const loadResult = Tsconfig.loadSync(process.cwd(), undefined);
const absolutePathMappings = [
  { pattern: "@Modules/*", paths: [`/home/jm/Projects/Modules/*`] },
];
const mp = TsconfigPaths.matchFromAbsolutePaths(absolutePathMappings)
const matchPath = TsconfigPaths.createMatchPath(
    join(
      dirname(loadResult.path),
      loadResult.config.compilerOptions.baseUrl
    ),
    loadResult.config.compilerOptions.paths
  );
  
  // Match a path and log result
  const result = matchPath("@Modules/fs");
  console.log(result);
const abosolutePathMappings = [
    {
      pattern: "longest/pre/fix/*",
      paths: [join("/absolute", "base", "url", "foo2", "bar")]
    },
    { pattern: "pre/fix/*", paths: [join("/absolute", "base", "url", "foo3")] },
    { pattern: "*", paths: [join("/absolute", "base", "url", "foo1")] }
  ];

TsconfigPaths.matchFromAbsolutePaths({
    "@Modules"
})

 */