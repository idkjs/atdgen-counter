%raw
{|require('isomorphic-fetch')|};

let baseUrl = "http://localhost:3003/";
let countersUrl = baseUrl ++ "counters";

type t = RemoteData.t(array(Counter.t));

exception DecodeError(string);
exception ServerError(string);
let fetchCounters = () => {
  Js.Promise.(
    Fetch.fetch(countersUrl)
    |> then_(Fetch.Response.json)
    |> then_(json => resolve(Counter_bs.read_t(json)))
    //  switch (Counter_bs.read_t(json)) {
    //  | Belt.Result.Ok(res) => resolve(res)
    //  | Error(err) =>
    //    reject(DecodeError({j|Decode error in ($path): $message|j}))
    //  }
    |> catch(_ => reject(ServerError("Something went wrong")))
  );
};

// let fetchCounters = () => {
//   Js.Promise.(
//     Fetch.fetch(countersUrl)
//     |> then_(Fetch.Response.json)
//     |> then_(json =>
//          switch (Counter_bs.read_t(json)) {
//          | Ok(res) => resolve(res)
//          | Error(err) =>
//            reject(DecodeError({j|Decode error in ($path): $message|j}))
//          }
//        )
//     |> catch(_ => reject(ServerError("Something went wrong")))
//   );
// };
//  |> then_(res => SuccessData(res) |> dispatch|> resolve)
let x = fetchCounters();
Js.log(x);
