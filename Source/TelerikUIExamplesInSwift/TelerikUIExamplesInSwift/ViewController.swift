//
//  ViewController.swift
//  Swift Examples
//
//  Copyright (c) 2014 Telerik. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    var examples = [ExampleInfo]()
    let table = UITableView()
    var selectedRow: NSInteger = -1
    
    func initWithExample(example:ExampleInfo) {
        for e in example.examples {
            self.examples.append(e)
        }
        self.title = example.title
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.view.addSubview(table)

        if (examples.count == 0) {
            
            examples.append(ExampleInfo(title: "Chart", exampleList:[
                    ExampleInfo(title: "Chart Types", exampleList:[
                            ExampleInfo(title: "Column / Bar chart") { ColumnAndBarChart() },
                            ExampleInfo(title: "Line / Area / Spline chart") { LineAreaSpline() },
                            ExampleInfo(title: "Scatter chart") { ScatterChart() },
                            ExampleInfo(title: "Bubble chart") { BubbleChart() },
                            ExampleInfo(title: "Pie chart") { PieDonut() },
                            ExampleInfo(title: "Stacked Column chart") { StackedColumnChart() },
                            ExampleInfo(title: "Stacked Area chart") { StackedAreaChart() },
                            ExampleInfo(title: "Financial chart") { FinancialChart() },
                            ExampleInfo(title: "Indicators") { Indicators() },
                        ]),
                    ExampleInfo(title: "Axis Types", exampleList:[
                            ExampleInfo(title: "Numeric axis") { NumericAxis() },
                            ExampleInfo(title: "Categorical axis") { CategoricalAxis() },
                            ExampleInfo(title: "Date/Time axis") { DateTimeAxis() },
                            ExampleInfo(title: "Multiple axes") { MultipleAxes() },
                            ExampleInfo(title: "Negative values") { NegativeValues() }
                        ]),
                    ExampleInfo(title: "Animations", exampleList:[
                            ExampleInfo(title: "Default animations") { DefaultAnimation() },
                            ExampleInfo(title: "Custom animation - line chart") { CustomAnimationLineChart() },
                            ExampleInfo(title: "Custom animation - area chart") { CustomAnimationAreaChart() },
                            ExampleInfo(title: "Custom animation - pie chart") { CustomAnimationPieChart() },
                            ExampleInfo(title: "UIKit dynamics animation") { UIKitDynamicsAnimation() }
                        ]),
                    ExampleInfo(title: "Binding", exampleList:[
                            ExampleInfo(title: "Bind with data point") { BindWithDataPoint() },
                            ExampleInfo(title: "Bind with custom object") { BindWithCustomObject() },
                            ExampleInfo(title: "Bind with delegate") { BindWithDelegate() }
                        ]),
                    ExampleInfo(title: "Pan/Zoom") { PanZoom() },
                    ExampleInfo(title: "Customize") { Customize() },
                    ExampleInfo(title: "Annotations", exampleList:[
                            ExampleInfo(title: "Band and line annotations") { BandAndLineAnnotation() },
                            ExampleInfo(title: "Balloon annotation") { BalloonAnnotation() },
                            ExampleInfo(title: "Layer annotation") { LayerAnnotation() },
                            ExampleInfo(title: "View annotation") { ViewAnnotation() },
                            ExampleInfo(title: "Cross line annotation") { CrossLineAnnotation() },
                            ExampleInfo(title: "Custom annotation") { CustomAnnotation() },
                            ExampleInfo(title: "Trackball") { Trackball() }
                        ]),
                    ExampleInfo(title: "Point Labels", exampleList: [
                        ExampleInfo(title: "Point Labels") { PointLabels() },
                        ExampleInfo(title: "Custom Label") { CustomPointLabels() },
                        ExampleInfo(title: "Custom Label Render") { CustomPointLabelRender() }
                        ]),
                    ExampleInfo(title: "Live data") { LiveData() }
                ]))
            
            examples.append(ExampleInfo(title: "Calendar", exampleList:[
                    ExampleInfo(title: "Calendar with events") { CalendarWithEvents() },
                    ExampleInfo(title: "View modes") { CalendarViewModes() },
                    ExampleInfo(title: "Transition effects") { CalendarTransitonEffects() },
                    ExampleInfo(title: "Selection") { CalendarSelection() },
                    ExampleInfo(title: "iOS 7 style calendar") { iOS7StyleCalendar() },
                    ExampleInfo(title: "Customization") { CalendarCustomization() },
                    ExampleInfo(title: "EventKit data binding") { CalendarEventKitDataBinding() },
                    ExampleInfo(title: "Localized calendar") { LocalizedCalendar() },
                    ExampleInfo(title: "Inline events") { InlineEvents() },
                ]))
            
            examples.append(ExampleInfo(title: "Feedback") { FeedbackExampleController(nibName: "FeedbackExampleController", bundle: nil) })
            
            examples.append(ExampleInfo(title: "SideDrawer", exampleList: [
                ExampleInfo(title: "Getting Started") { SideDrawerGettingStarted() },
                ExampleInfo(title: "Transitions") { SideDrawerTransitions() },
                ExampleInfo(title: "Custom Content") { SideDrawerCustomContent() },
                ExampleInfo(title: "Custom Transition") { SideDrawerCustomTransition() },
                ExampleInfo(title: "Positions") { SideDrawerPositions() }
                ]))
            
            examples.append(ExampleInfo(title: "DataSource", exampleList:[
                    ExampleInfo(title: "Getting started") { DataSourceGettingStarted() },
                    ExampleInfo(title: "Descriptors API") { DataSourceDescriptorsAPI() },
                    ExampleInfo(title: "Bind with UI controls") { DataSourceUIBindings() },
                    ExampleInfo(title: "Consume web service") { DataSourceWithWebService() },
                ]))
            

            examples.append(ExampleInfo(title: "ListView", exampleList: [
                    ExampleInfo(title: "Getting started") { ListViewGettingStarted() },
                    ExampleInfo(title: "Swipe cell") { ListViewSwipe() },
                    ExampleInfo(title: "Items reorder") { ListViewReorder() },
                    ExampleInfo(title: "Selection") { ListViewSelection() },
                    ExampleInfo(title: "Grouping") { ListViewGroups() },
                    ExampleInfo(title: "Layouts"){ ListViewLayout() },
                    ExampleInfo(title: "Animations") { ListViewAnimations() },
                    ExampleInfo(title: "Load on demand") { ListViewLoadOnDemand() },
                    ExampleInfo(title: "Pull to refresh") { ListViewPullToRefresh() },
                ]))
            
            self.title = "Examples"
        }

        table.delegate = self
        table.dataSource = self
        self.view.addSubview(table)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        table.frame = self.view.bounds
    }
    
//MARK: - UITableViewDataSource

    func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return examples.count
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        var cell: UITableViewCell? = tableView.dequeueReusableCellWithIdentifier("examplescell") as! UITableViewCell?
        if cell == nil {
            cell = UITableViewCell(style: UITableViewCellStyle.Default, reuseIdentifier: "examplescell")
            cell!.selectionStyle = UITableViewCellSelectionStyle.None
        }
        var info = examples[indexPath.row]
        cell!.textLabel!.text = info.title
        return cell!
    }
    
//MARK: - UITableViewDelegate
    
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        var e = examples[indexPath.row]
        var controller = e.createController()
        self.navigationController?.pushViewController(controller, animated: true)
    }
}

