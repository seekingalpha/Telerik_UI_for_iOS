//
//  BandAndLineAnnotations.swift
//  Swift Examples
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

import Foundation

class BandAndLineAnnotation:ExampleViewController {
    
    let chart = TKChart()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        chart.frame = self.exampleBoundsWithInset
        chart.autoresizingMask = UIViewAutoresizing.FlexibleWidth | UIViewAutoresizing.FlexibleHeight
        self.view.addSubview(chart)
        
        for i in 0..<2 {
            var points = [TKChartDataPoint]()
            for i in 0..<20 {
                points.append(TKChartDataPoint(x:Int(arc4random() % 1450), y:Int(arc4random() % 150)))
            }
            chart.addSeries(TKChartScatterSeries(items: points))
        }
        
        // Add some grid line annotations
        chart.addAnnotation(TKChartGridLineAnnotation(value: 80, forAxis: chart.yAxis, withStroke: TKStroke(color: UIColor.redColor(), width: 0.5)))
        chart.addAnnotation(TKChartGridLineAnnotation(value: 600, forAxis: chart.xAxis))

        // Add two band annotations
        let color = UIColor(red: 1, green: 0, blue: 0, alpha: 0.4)
        chart.addAnnotation(TKChartBandAnnotation(range: (TKRange(minimum: 10, andMaximum: 40)),
                forAxis: chart.yAxis, withFill: TKSolidFill(color: color), withStroke: nil))
            
        let a = TKChartBandAnnotation(range: TKRange(minimum: 900, andMaximum: 1500), forAxis: chart.xAxis)
        a.style.fill = TKSolidFill(color: UIColor(red: 0, green: 1, blue: 0, alpha: 0.3))
        chart.addAnnotation(a)
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}