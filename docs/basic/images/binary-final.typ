#set page(width: auto, height: auto, margin: 0.5cm)
#set text(font: "Noto Sans CJK SC", 12pt)
#set table(stroke: 0.6pt, align: center)

#let valid(colspan) = table.cell(colspan: colspan, fill: rgb("#57be6a"), text(white, 14pt)[*Hợp lệ*])
#let invalid(colspan) = table.cell(colspan: colspan, fill: rgb("#e75e58"), text(white, 14pt)[*Không hợp lệ*])
#let dots = [$dots.h$] * 2

#table(
  columns: 7 * (1.8cm,),
  valid(3), invalid(4),
  [Nhỏ nhất], [$"L"$], [$"MID"$],
  [$"R"$], dots, dots, [Lớn nhất],
)

#align(center, text(14pt)[hoặc])

#table(
  columns: 7 * (1.8cm,),
  valid(4), invalid(3),
  [Nhỏ nhất], dots, dots, [$"L"$],
  [$"MID"$], [$"R"$], [Lớn nhất],
)

#pagebreak()

#table(
  columns: 7 * (1.8cm,),
  valid(3), invalid(4),
  [Nhỏ nhất], dots, [$"L,MID"$],
  [$"R"$], dots, dots, [Lớn nhất],
)

#align(center, text(14pt)[hoặc])

#table(
  columns: 7 * (1.8cm,),
  valid(4), invalid(3),
  [Nhỏ nhất], dots, dots, [$"L"$],
  [$"MID,R"$], dots, [Lớn nhất],
)
