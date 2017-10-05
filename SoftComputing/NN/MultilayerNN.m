#   CONSTANT DEVLARATION
HIDDEN_LAYER_SIZE=2;
TOTAL_INPUT_FEATURE=2;
TOTAL_OUTPUTS = 2;
TOTAL_TRAINING_DATA=4;

#   PROGRAM START
feature_input = [0,0;0,1;1,0;1,1]
output = [ 0;1;1;0 ]
#   Initializing weights
input_layer=[0.1,0.2 ; 0.3,0.4] #rand(TOTAL_INPUT_FEATURE,HIDDEN_LAYER_SIZE) 
hidden_layer=[0.5 ; 0.6] #rand(HIDDEN_LAYER_SIZE,TOTAL_OUTPUTS) 
delta_h = rand(HIDDEN_LAYER_SIZE,1);

for i=[1:TOTAL_TRAINING_DATA]
temp=reshape(feature_input(i,:),2,1);
temp_summation = temp.*input_layer;
temp_summation = sum(temp_summation,2);
temp_summation=reshape(temp_summation,2,1);
final_val=temp_summation.*hidden_layer;
final_val=sum(final_val);
delta_l=final_val - output(i)
delta_h=(hidden_layer')*delta_l
end
