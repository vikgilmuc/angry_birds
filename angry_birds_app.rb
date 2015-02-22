require 'sinatra'
require 'serialport'
 
 configure do
  #$mode = 3
   @@serial_port = SerialPort.new("/dev/tty.usbmodem411", 9600, 8, 1, SerialPort::NONE)
   
 end
 
# get '/' do
#   #erb :index
# end
 
get '/' do
  "Hello World"
  #erb :index
  
end


get '/1' do
  
  @@serial_port.write (1)
  "1"
end

get '/2' do
  
  @@serial_port.write (2)
  "2"
end

get '/3' do
  
  @@serial_port.write (3)
  "3"
end

get '/4' do
  
  @@serial_port.write (4)
  "4"
end

get '/5' do
@@serial_port.write (5)
  "5"

  end

get '/6' do
@@serial_port.write (6)
  "6"

  end




get '/0' do
  $serial_port.write(0)
  $serial_port.read
end

# post '/:mode' do
#   $mode = params[:mode]
#   $serial_port.write "#{$mode}"
#   redirect '/'
# end
 
# __END__
 
#  @@index
 
# <!DOCTYPE html>
# <html>
#   <head>
#     <title>Traffic Light</title>
#   </head>
 
#   <body>
#     <p>Current Mode: <%= $mode %></p>
 
#     <form action="/1" method="post">
#       <input type="submit" value="Red"/>
#     </form>
 
#     <form action="/2" method="post">
#       <input type="submit" value="Yellow"/>
#     </form>
 
#     <form action="/3" method="post">
#       <input type="submit" value="Green"/>
#     </form>
 
#     <form action="/4" method="post">
#       <input type="submit" value="Party Mode"/>
#     </form>
#   </body>
# </html>