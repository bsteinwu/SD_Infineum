import dash
from dashboard import layouts

app = dash.Dash(__name__, suppress_callback_exceptions=True)
app.title = 'Senior Design Program'
app.layout = layouts.init(app)
