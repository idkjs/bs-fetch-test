let baseUrl = "https://localhost:8000";

type prices = {
  nasdaq: int,
  cac40: int
};

type stockItem = {
  timestamp: int,
  index: int,
  stocks: prices
};

module Decode = {
  let prices = (json) => {
    open! Json.Decode;
    {nasdaq: json |> field("nasdaq", int), cac40: json |> field("cac40", int)}
  };
  let stockItem = (json) =>
    Json.Decode.{
      timestamp: json |> field("timestamp", int),
      index: json |> field("index", int),
      stocks: json |> field("stocks", prices)
    };
};

let fetchdata =
  Js.Promise.(
    Bs_fetch.fetch("http://localhost:8000")
    |> then_(Bs_fetch.Response.text)
    |> then_((jsonText) => resolve(Js.Json.parseExn(jsonText)))
    /* |> Decode.stockItem */
    /* |> Js.log */
  );

/* fetchdata |> Decode.stockItem |> Js.log; */
fetchdata |> Js.log;
/* [
    {
        "timestamp": 1513638108486,
        "index": 1,
        "stocks": {
            "NASDAQ": 15.144926065887098,
            "CAC40": 145.01172231656113
        }
    },
    {
        "timestamp": 1513638109487,
        "index": 2,
        "stocks": {
            "NASDAQ": 15.131505666333803,
            "CAC40": 145.011722316566
        }
    }
   ] */
/* let parseStockItem = (json: Js.Json.t) : stockItem =>
     Json.Decode.{
       timestamp: field("timestamp", int, json),
       index: field("index", int, json),
       stocks: field("stocks", prices, json)
     };

   /* create function to get the items field off the json response */
   let parseStocksJson = (json) => Json.Decode.array(parseStockItem); */
/* let fetchJoke = (_name) =>
   Bs_fetch.fetch(chuckApi)
   |> Js.Promise.then_(Bs_fetch.Response.json)
   |> Js.Promise.then_((json) => Js.Promise.resolve(Js.log(parseChuckJokeJson(json)))); */
/* let data =
     Js.Promise.(
       Bs_fetch.fetch("https://localhost:8000")
       |> Js.Promise.then_(Bs_fetch.Response.json)
       |> Js.Promise.then_((json) => Js.Promise.resolve(Js.log(parseStocksJson(json))))
     );

   Js.log(data); */