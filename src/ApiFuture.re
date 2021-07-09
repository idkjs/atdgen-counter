let baseUrl = "http://localhost:3003/";
let countersUrl = baseUrl ++ "counters";

type t = RemoteData.t(array(Counter.t));

exception DecodeError(string);
exception ServerError(string);

type error = [ | `FetchCountersError(Js.Promise.error)];

type status =
  | ClientError(int)
  | ServerError(int);

type response = {
  status,
  json: Js.Json.t,
};

let fetchCounters = () => {
  Fetch.fetch(countersUrl)
  ->FutureJs.fromPromise(fetchError => `FetchCountersError(fetchError))
  // OK = fetch did something. Map result to easily consumable type.
  ->Future.flatMapOk(apiResponse =>
      Fetch.Response.json(apiResponse)
      ->FutureJs.fromPromise(err => `FetchCountersError(err))
      ->Future.mapOk(json => {

          {json};
        })
    );
};


// let fetchCounters = () => {
//   Js.Promise.(
//     Fetch.fetch(countersUrl)
//     |> then_(Fetch.Response.json)
//     |> then_(json =>
//          switch (Counter.decode(json)) {
//          | Ok(res) => resolve(res)
//          | Error(err) =>
//            reject(DecodeError({j|Decode error in ($path): $message|j}))
//          }
//        )
//     |> catch(_ => reject(ServerError("Something went wrong")))
//   );
// };
