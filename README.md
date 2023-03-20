# ROSNeuro DC filter

This ROSNeuro filter plugin implements a simple DC filter to remove the DC component from the provided input data. 

## Algorithm:
The filter applies DC removal from the data by substracting the mean value from each channel. The mean value is computed over all the provided samples.

## YAML configuration:
```
DcCfgTest:
  name: dc
  type: DcFilterFloat
```
*No additional parameters, but name and type*
