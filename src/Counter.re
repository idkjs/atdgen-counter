type t = Counter_t.t;

type response = {json: Js.Json.t};

module Id = {
  type t = string;

  let encode = t => Atdgen_codec_runtime.Encode.encode(t);
  let decode = t => Atdgen_codec_runtime.Decode.decode(t);
};

type counter = {
  id: Id.t,
  name: string,
  value: int,
};
let decode = t => Atdgen_codec_runtime.Decode.decode(t);
