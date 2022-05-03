from dash import Dash
import dash_core_components as dcc
import dash_html_components as html

print('Code Started')

def init(app:Dash):

    import dashboard.layouts.Shelf_1 as Shelf_1
    Shelf_1.callbacks.register(app)
    #tabs.append(Shelf_1.layout.build())

    import dashboard.layouts.Shelf_2 as Shelf_2
    #Shelf_2.callbacks.register(app)
    #tabs.append(Shelf_2.layout.build())

    import dashboard.layouts.Shelf_3 as Shelf_3
    #Shelf_2.callbacks.register(app)
    #tabs.append(Shelf_3.layout.build())

    return html.Div(children=[

            dcc.Store(id='place_holder'),

            dcc.Store(id='place_holder_2'),

            html.Div([
                html.Label('Infineum Smart Storage Device Beta-Prototype')
            ],style={'font-size':'50px', 'height': '100px'}),

            html.Div(children=[
                html.Div([
                    dcc.Tabs(id='shelves', value='Shelf_1',
                    children=[
                        dcc.Tab(label='Shelf 1', value='Shelf_1'),
                        dcc.Tab(label='Shelf 2', value='Shelf_2'),
                        dcc.Tab(label='Shelf 3', value='Shelf_3')
                    ],
                    style={'height':'50%'}),
                ]),
            
                html.Div(id='Current_shelf'),

                html.Div(style={'hieght':'100px'}),

                html.Div(id='sample_info'),

                html.Div([],style={'height':'50px'}),

            ], style={'display':'inline-block', 'width':'55%', 'vertical-align':'top'}),


            html.Div([

                html.Div(style={'height':'50px'}),

                html.Div([
                    html.Button('Export',id='export', n_clicks=0),
                ], style={'margin-left': '40px', 'display':'inline-block'}),

                html.Div([
                    html.Button('Import',id='import', n_clicks=0),
                ], style={'margin-left': '60px', 'display':'inline-block'}),

                html.Div(style={'height':'20px'}),

                html.Div([
                    html.Label('Placeholder',style={'width':'80px'})
                ], style={'margin-left':'20px','width':'100px','display':'inline-block'}),

                html.Div([
                    html.Label('ELN Number',style={'width':'80px'})
                ], style={'width':'100px','display':'inline-block'}),

                html.Div([
                    html.Label('Arrival Date',style={'width':'80px'})
                ], style={'width':'100px','display':'inline-block'}),

                html.Div([
                    html.Label('Experation Date',style={'width':'100px'})
                ], style={'width':'130px','display':'inline-block'}),

                html.Div(style={'height':'20px'}),

                html.Div([
                    html.Label('Example input:',style={'width':'80px'})
                ], style={'margin-left':'20px','width':'100px','display':'inline-block'}),

                html.Div([
                    html.Label('12345678',style={'width':'80px'})
                ], style={'margin-left':'20px', 'width':'100px','display':'inline-block'}),

                html.Div([
                    html.Label('1/15/22',style={'width':'80px'})
                ], style={'width':'100px','display':'inline-block'}),

                html.Div([
                    html.Label('5/3/25',style={'width':'100px'})
                ], style={'width':'130px','display':'inline-block'}),

                html.Div(style={'height':'20px'}),

                html.Div([
                    dcc.Input(id='input_1_placeholder', style={'width':'80px'})
                ], style={'margin-left':'10px', 'width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_1_ELN', style={'width':'80px'}),
                ], style={'width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_1_arrival', style={'width':'80px'})
                ], style={'width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_1_experation', style={'width':'80px'})
                ], style={'width':'110px','display':'inline-block'}),

                html.Div(style={'height':'20px'}),

                html.Div([
                    dcc.Input(id='input_2_placeholder', style={'width':'80px'})
                ], style={'margin-left':'10px','width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_2_ELN', style={'width':'80px'}),
                ], style={'width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_2_arrival', style={'width':'80px'})
                ], style={'width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_2_experation', style={'width':'80px'})
                ], style={'width':'110px','display':'inline-block'}),

                html.Div(style={'height':'20px'}),

                html.Div([
                    dcc.Input(id='input_3_placeholder', style={'width':'80px'})
                ], style={'margin-left':'10px','width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_3_ELN', style={'width':'80px'}),
                ], style={'width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_3_arrival', style={'width':'80px'})
                ], style={'width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_3_experation', style={'width':'80px'})
                ], style={'width':'110px','display':'inline-block'}),

                html.Div(style={'height':'20px'}),

                html.Div([
                    dcc.Input(id='input_4_placeholder', style={'width':'80px'})
                ], style={'margin-left':'10px', 'width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_4_ELN', style={'width':'80px'}),
                ], style={'width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_4_arrival', style={'width':'80px'})
                ], style={'width':'110px','display':'inline-block'}),

                html.Div([
                    dcc.Input(id='input_4_experation', style={'width':'80px'})
                ], style={'width':'110px','display':'inline-block'}),

                html.Div(style={'height':'20px'}),

                html.Div([
                    html.Button('Submit', id='submit_button', n_clicks=0, style = {'width':'200px','margin-left':'120px', 'background-color':'#e7e7e7'})
                ]),

                html.Div(style={'height':'30px'}),

                html.Div([
                    html.Button('Completed Action', id='finalize_button', n_clicks=0, style = {'width':'200px','margin-left':'120px', 'background-color':'#e7e7e7'})
                ]),

                html.Div(style={'height':'30px'}),

                html.Div(id='user_entry')
                
            ], style={'display':'inline-block','width':'45%','vertical-align':'top'})
        ])