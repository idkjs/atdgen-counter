(* Auto-generated from "Counter.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type id = Counter_t.id

type t = Counter_t.t = { id: id option; name: string; value: int }

val read_id :  id Atdgen_codec_runtime.Decode.t

val write_id :  id Atdgen_codec_runtime.Encode.t

val read_t :  t Atdgen_codec_runtime.Decode.t

val write_t :  t Atdgen_codec_runtime.Encode.t

