type prices = {
  nasdaq: int,
  cac40: int,
};

type t = {
  timestamp: int,
  index: int,
  stocks: prices,
};
module Decode = {
  let prices = json => {
    open! Json.Decode;
    {
      nasdaq: json |> field("nasdaq", int),
      cac40: json |> field("cac40", int),
    };
  };
  let stockItem = json =>
    Json.Decode.{
      timestamp: json |> field("timestamp", int),
      index: json |> field("index", int),
      stocks: json |> field("stocks", prices),
    };
};
