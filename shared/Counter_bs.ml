(* Auto-generated from "Counter.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type id = Counter_t.id

type t = Counter_t.t = { id: id option; name: string; value: int }

let write__1 = (
    Atdgen_codec_runtime.Encode.string
  |> Atdgen_codec_runtime.Encode.contramap (Transform.Id.unwrap)
)
let read__1 = (
  (
    Atdgen_codec_runtime.Decode.string
  ) |> (Atdgen_codec_runtime.Decode.map (Transform.Id.wrap))
)
let write_id = (
  write__1
)
let read_id = (
  read__1
)
let write__2 = (
  Atdgen_codec_runtime.Encode.option_as_constr (
    write_id
  )
)
let read__2 = (
  Atdgen_codec_runtime.Decode.option_as_constr (
    read_id
  )
)
let write_t = (
  Atdgen_codec_runtime.Encode.make (fun (t : t) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field_o
            (
            write_id
            )
          ~name:"id"
          t.id
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"name"
          t.name
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"value"
          t.value
      ]
    )
  )
)
let read_t = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          id =
            Atdgen_codec_runtime.Decode.decode
            (
              read_id
              |> Atdgen_codec_runtime.Decode.fieldOptional "id"
            ) json;
          name =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "name"
            ) json;
          value =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "value"
            ) json;
      } : t)
    )
  )
)
