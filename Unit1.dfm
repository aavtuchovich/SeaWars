object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1052#1086#1088#1089#1082#1086#1081' '#1073#1086#1081
  ClientHeight = 500
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIForm
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 61
    Width = 31
    Height = 24
    Caption = #1042#1099
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 368
    Top = 61
    Width = 108
    Height = 24
    Caption = #1050#1086#1084#1087#1100#1102#1090#1077#1088
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DrawGrid1: TDrawGrid
    AlignWithMargins = True
    Left = 8
    Top = 48
    Width = 305
    Height = 289
    TabStop = False
    BorderStyle = bsNone
    ColCount = 11
    DefaultColWidth = 25
    FixedCols = 0
    RowCount = 11
    FixedRows = 0
    ScrollBars = ssNone
    TabOrder = 0
  end
  object DrawGrid2: TDrawGrid
    Left = 344
    Top = 48
    Width = 289
    Height = 289
    BorderStyle = bsNone
    ColCount = 11
    DefaultColWidth = 25
    FixedCols = 0
    RowCount = 11
    FixedRows = 0
    ScrollBars = ssNone
    TabOrder = 1
    OnClick = DrawGrid2Click
  end
  object Button1: TButton
    Left = 264
    Top = 360
    Width = 129
    Height = 25
    Caption = #1048#1075#1088#1072#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object Timer1: TTimer
    Interval = 1
    Left = 312
    Top = 296
  end
end
