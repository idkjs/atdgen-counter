// let get = (url, decode) =>
//   Js.Promise.(
//     Fetch.fetchWithInit(
//       url,
//       Fetch.RequestInit.make(~method_=Get, ()),
//     )
//     |> then_(Fetch.Response.json)
//     |> then_(json => json |> decode |> resolve)
//   );
//   let v: Counter_t.id =
//   get(
//     "http://localhost:8000/events",
//     Atdgen_codec_runtime.Decode.decode(Counter_bs.read_t),
//   );
