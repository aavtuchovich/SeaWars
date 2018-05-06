object Form1: TForm1
  Left = 0
  Top = 0
  HelpContext = 1
  BorderStyle = bsSingle
  Caption = #1052#1086#1088#1089#1082#1086#1081' '#1073#1086#1081
  ClientHeight = 337
  ClientWidth = 637
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIForm
  HelpFile = 'seawars.chm'
  Menu = MainMenu1
  OldCreateOrder = False
  Scaled = False
  OnActivate = FormActivate
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
  object Label3: TLabel
    Left = 344
    Top = 10
    Width = 151
    Height = 32
    Caption = #1055#1088#1086#1090#1080#1074#1085#1080#1082
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 10
    Width = 43
    Height = 32
    Caption = #1042#1099
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DrawGrid1: TDrawGrid
    AlignWithMargins = True
    Left = 8
    Top = 48
    Width = 257
    Height = 249
    TabStop = False
    BorderStyle = bsNone
    ColCount = 10
    DefaultColWidth = 25
    Enabled = False
    FixedCols = 0
    RowCount = 10
    FixedRows = 0
    ScrollBars = ssNone
    TabOrder = 0
  end
  object DrawGrid2: TDrawGrid
    Left = 344
    Top = 48
    Width = 257
    Height = 249
    BorderStyle = bsNone
    ColCount = 10
    DefaultColWidth = 25
    Enabled = False
    FixedCols = 0
    RowCount = 10
    FixedRows = 0
    ScrollBars = ssNone
    TabOrder = 1
    OnClick = DrawGrid2Click
  end
  object Button1: TButton
    Left = 240
    Top = 303
    Width = 129
    Height = 25
    Caption = #1048#1075#1088#1072#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 296
    Top = 176
  end
  object MainMenu1: TMainMenu
    Left = 296
    Top = 224
    object Buhf1: TMenuItem
      Caption = #1048#1075#1088#1072
      object N1: TMenuItem
        Caption = #1053#1086#1074#1072#1103
        OnClick = N1Click
      end
      object N2: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = N2Click
      end
    end
    object N4: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      OnClick = N4Click
    end
    object N3: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      OnClick = N3Click
    end
  end
end
