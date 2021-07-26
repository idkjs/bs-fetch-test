type req;

type res;

type server;
let baseUrl = "https://localhost:8000";
let data_file = "stocks.json";

let file_content = Node.Fs.readFileAsUtf8Sync(data_file);
[@bs.module] external micro: ((req, res) => string) => server = "micro";

[@bs.send] external listen: (server, int) => unit = "listen";

let port = 8000;
let add = (a, b) => a + b;

let server = micro((_req, _res) => file_content);

// let server = micro((req, res) => "Hello, world!");

Js.log({j|http://localhost:$port/|j});

listen(server, port);
